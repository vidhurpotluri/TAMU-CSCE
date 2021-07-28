// global
var currentURL;
var movie = 1;
var onSearchBarText;

window.onload = function(){

	var input = document.getElementById("searchInput");
	currentURL = input;
	input.addEventListener("keyup", enterHandler); 
	document.getElementById("logo").addEventListener("click",goToMainpage);
	function goToMainpage()
	{
		currentURL = '';
		window.location.search = currentURL;
	}
	document.getElementById('back-button').addEventListener('click',goBack);
	function goBack() {
  		window.history.back();
  	}

	function ParseURLParameter(Parameter)
	{

		var FullURL = window.location.search.substring(1);

		var ParametersArray = FullURL.split('&');
		for (var i =0;i<ParametersArray.length;i++)
		{
			var CurrentParameter = ParametersArray[i].split('=');
			if (CurrentParameter[0] == Parameter)
			{
				return CurrentParameter[1];
			}
		}
	}

	var PageName = ParseURLParameter('page');
	if (typeof PageName !== 'undefined') {

		if (PageName == 'movie' || PageName == 'tv') {
			// do something
			var id = ParseURLParameter('id');
			var movietype;
			if (PageName=='movie') movietype=1; else movietype=2;
			setUpPage(movietype,id);
			document.getElementById('movie-content').style.display = 'block';
			document.getElementById('back-button').style.display = 'block';
		}
		else if (PageName == 'search')
		{
			// do something
			var searchText = ParseURLParameter('text');
			var toprint = searchText.replace("%20"," ");
			document.getElementById("searchInput").value = toprint;
			var movietype = ParseURLParameter('movie');
			document.getElementById('entertainment').value = movietype;
			searchMovie(movietype,searchText);
			document.getElementById('default-content').style.display = 'block';
			document.getElementById('search-content').style.display = 'block';
		}
		else if (PageName == 'filter')
		{
			var genreID = ParseURLParameter('genre');
			document.getElementById('genre').value = genreID;
			var languageID = ParseURLParameter('language');
			document.getElementById('language').value = languageID;
			var movietype = ParseURLParameter('movie');
			document.getElementById('entertainment').value = movietype;
			searchbyFilter(movietype,genreID,languageID);
			document.getElementById('default-content').style.display = 'block';
			document.getElementById('search-content').style.display = 'block';
		}
	} else { //main page
		document.getElementById('default-content').style.display = 'block';
	}

} 

// CODE FOR MAIN PAGE + SEARCH BEGINS HERE

function getSearchInput()
{
	var searchText = document.getElementById("searchInput").value;
	return searchText;
	//location.reload(forceGet);
	
}

function enterHandler()
{
  if (event.keyCode === 13) {
  	var searchText = getSearchInput();
  	onSearchBarText = searchText;
  	console.log(onSearchBarText);
  	movie = document.getElementById("entertainment").value;
  	currentURL = 'page=search' + '&movie=' + movie + '&text=' + searchText;
	window.location.search = currentURL;
  }
}

function filterHandler()
{
	var genreID = document.getElementById("genre").value;
	var languageID = document.getElementById("language").value;
	movie = document.getElementById("entertainment").value;
	currentURL = 'page=filter' + '&movie=' + movie +
				'&genre=' + genreID + '&language=' + languageID;
	window.location.search = currentURL;
}


function searchbyFilter(movietype,genreID,languageID)
{
	var request = new XMLHttpRequest();
	var container = document.getElementById('searchResult');
	container.innerHTML = "";
	container.setAttribute('class','container');
	var requestText = '';
	if (movietype==1) requestText = 'https://api.themoviedb.org/3/discover/movie?api_key=c0a26b968da837babc8f62fd7f411943&language=en-US&sort_by=popularity.desc&include_adult=false';
	else requestText = 'https://api.themoviedb.org/3/discover/tv?api_key=c0a26b968da837babc8f62fd7f411943&language=en-US&sort_by=popularity.desc&include_adult=false';
	if (genreID) requestText += '&with_genres='+ genreID;
	if (languageID) requestText += '&with_original_language=' + languageID;
	request.open('GET',requestText,true);
	//request.open('GET','https://ghibliapi.herokuapp.com/films',true);
	request.onload = function()
	{
		if (request.status == 200)
		{
			var data = JSON.parse(this.response);
			var movies = data.results;
			movies.forEach(func);			
			function func(movie)
			{
				const card = document.createElement('div');
				card.setAttribute('class','card');

				const poster = document.createElement('img');
				var poster_added = 0;
				if (movie.poster_path!=null)
				{
					var posterPath = 'http://image.tmdb.org/t/p/w200' +  movie.poster_path;
					poster.src = posterPath;
					if (poster.status!=502) 
					{
						card.appendChild(poster);
						poster_added = 1;
					}
				}
				if (poster_added==0)
				{					
					poster.src = 'images/imageplaceholder.png';
					
					const h1 = document.createElement('h2');
					h1.textContent = movie.title;
					card.appendChild(h1);
					card.appendChild(poster);
				}

				var id = movie.id;
				card.addEventListener("click", goToMovie);

				function goToMovie()
				{
					if (movietype==1) currentURL = 'page=movie&' + 'id=' + id;
					else currentURL = 'page=tv&' + 'id=' + id;
					window.location.search = currentURL;
				}
				
				container.appendChild(card);

			}
		}
		else
		{
			console.log ('Error');

		}
	}

	request.send();

}




function searchMovie(movietype,searchText)
{
	var request = new XMLHttpRequest();
	var container = document.getElementById('searchResult');
	container.innerHTML = "";
	container.setAttribute('class','container');
	
	var requestText ='';
	if (movietype==1) requestText+='https://api.themoviedb.org/3/search/movie?query=';
	else requestText +='https://api.themoviedb.org/3/search/tv?query='
	requestText += searchText + '&api_key=c0a26b968da837babc8f62fd7f411943&language=en-US&page=1&include_adult=false';
	request.open('GET',requestText,true);
	//request.open('GET','https://ghibliapi.herokuapp.com/films',true);
	request.onload = function()
	{
		if (request.status == 200)
		{
			var data = JSON.parse(this.response);
			var movies = data.results;
			
			movies.sort(function(a,b){return b.popularity - a.popularity});
			movies.forEach(func);
			
			function func(movie)
			{
				const card = document.createElement('div');
				card.setAttribute('class','card');

				const poster = document.createElement('img');
				var poster_added = 0;
				if (movie.poster_path!=null)
				{
					var posterPath = 'http://image.tmdb.org/t/p/w200' +  movie.poster_path;
					poster.src = posterPath;
					if (poster.status!=502) 
					{
						card.appendChild(poster);
						poster_added = 1;
					}
				}
				console.log(movie.id);
				if (poster_added==0)
				{					
					poster.src = 'images/imageplaceholder.png';
					
					const h1 = document.createElement('h2');
					h1.textContent = movie.title;
					card.appendChild(h1);
					card.appendChild(poster);
				}

				var id = movie.id;
				card.addEventListener("click", goToMovie);

				function goToMovie()
				{
					if (movietype==1) currentURL = 'page=movie&' + 'id=' + id;
					else currentURL = 'page=tv&' + 'id=' + id;
					window.location.search = currentURL;
				}
				
				container.appendChild(card);

			}
		}
		else
		{
			console.log ('Error');

		}
	}

	request.send();
}


// CODE FOR MAIN PAGE + SEARCH ENDS HERE

function setUpPage(movietype,id)
{
	var request = new XMLHttpRequest();
	var type ='';
	console.log(movietype);
	if (movietype==1) type = 'movie'; else type ='tv';
	var requestText = 'https://api.themoviedb.org/3/'+ type + '/' + id + '?api_key=c0a26b968da837babc8f62fd7f411943&language=en-US';
	
	request.open('GET',requestText,true);
	request.onload = function()
	{
		if (request.status == 200)
		{
			var data = JSON.parse(this.response);
	
			// Load movie title - name
			console.log(data);
			var movie_name;
			if (movietype==1) movie_name = data.title;
			else movie_name = data.name;
			var movie_name_box = document.getElementById('movie-name')
			movie_name_box.textContent = movie_name;

			// Load movie description
			var movie_description = data.overview;
			var movie_description_box = document.getElementById('movie-description')
			movie_description_box.textContent = movie_description;

			// Load movie poster
			var movie_poster_box = document.getElementById('movie-poster')
			if (data.poster_path!=null) movie_poster_box.src = 'http://image.tmdb.org/t/p/w342' + data.poster_path;
			else movie_poster_box.src = 'images/logo.png';

			// Load movie background
			if (data.backdrop_path!=null)
				document.body.style.background = "linear-gradient(rgba(0,0,0,0.8),rgba(0,0,0,0.8)), url('" + 'http://image.tmdb.org/t/p/original' + data.backdrop_path +  "')";
			else document.body.style.background = "linear-gradient(rgba(0,0,0,0.8),rgba(0,0,0,0.8)), url('images/background.jpg')";
			document.body.style.backgroundPosition = "center";
			document.body.style.backgroundSize ="cover";

		}
		else
		{
			console.log ('whatthefuck');
		}
	}
	request.send();

	// Load casts

	var castRequest = new XMLHttpRequest();
	var requestText = 'https://api.themoviedb.org/3/' + type + '/' + id + '/credits?api_key=c0a26b968da837babc8f62fd7f411943&language=en-US';
	
	castRequest.open('GET',requestText,true);
	castRequest.onload = function()
	{
		if (castRequest.status == 200)
		{
			var data = JSON.parse(this.response);
			console.log(data);
			var casts = data.cast;
			var i = 1;
			var cast_div = document.getElementById('casting');
			for (cast of casts)
			{
				if (i==8) break;
				var cast_img = document.createElement('img');
				cast_img.src = 'http://image.tmdb.org/t/p/w45' + cast.profile_path;
				cast_img.title = cast.name;
				cast_div.appendChild(cast_img);
				i+=1;
			}
			
		}
		else
		{
			console.log ('whatthefuck');
		}
	}
	castRequest.send();

	// Load watching sources
	var sourcesRequest = new XMLHttpRequest();
	var requestText = "https://utelly-tv-shows-and-movies-availability-v1.p.rapidapi.com/idlookup?country=US&source_id=" + id + "&source=tmdb";
	
	sourcesRequest.open('GET',requestText,true);
	sourcesRequest.setRequestHeader("x-rapidapi-host", "utelly-tv-shows-and-movies-availability-v1.p.rapidapi.com");
	sourcesRequest.setRequestHeader("x-rapidapi-key", "82cde04d83mshfda8f72e60c0bb0p1d890fjsnced4af8fb43e");
	sourcesRequest.onload = function()
	{
		if (sourcesRequest.status == 200)
		{
			var data = JSON.parse(this.response);
			console.log(data);
			var sources = data.collection.locations;
	
			var i = 1;
			var source_div = document.getElementById('sources');
			for (source of sources)
			{
				if (i==8) break;
				
				var source_img = new Image();
				if (source.name == "DisneyPlusIVAUS") source_img.src = 'images/disneyplus.png';
				else source_img.src = source.icon;
				//source_img.src = 'images/sources/' + source.name + '.png';
				source_img.title = source.display_name;
				source_img.url = source.url;

			//	var url = source_img.url;
				source_img.onclick = function(evt) {
					var url = evt.currentTarget.url;
					
				    window.location.href = url;
				};
				source_div.appendChild(source_img);
				i+=1;
			}
		}
		else
		{
			console.log ('whatthefuck');
		}
	}
	sourcesRequest.send();

	// Load related movies

	var container = document.getElementById('related-movies');
	container.setAttribute('class','container');
	var relatedRequest = new XMLHttpRequest();
	var requestText = 'https://api.themoviedb.org/3/' + type + '/' + id + '/similar?api_key=c0a26b968da837babc8f62fd7f411943&language=en-US';
	relatedRequest.open('GET',requestText,true);
	relatedRequest.onload = function()
	{
		if (relatedRequest.status == 200)
		{
			var data = JSON.parse(this.response);
			var movies = data.results;

			//movies.sort(function(a,b){return b.popularity - a.popularity});
			var i = 1;
			for (movie of movies)
			{
				if (i==6) break;
				const card = document.createElement('div');
				card.setAttribute('class','card');
				card.style.width = 185;
				card.style.height = 250;

				const poster = document.createElement('img');
				var poster_added = 0;
				if (movie.poster_path!=null)
				{
					var posterPath = 'http://image.tmdb.org/t/p/w200' +  movie.poster_path;
					poster.src = posterPath;
					if (poster.status!=502) 
					{
						card.appendChild(poster);
						poster_added = 1;
					}
				}
				if (poster_added==0)
				{					
					poster.src = 'images/imageplaceholder.png';
					
					const h1 = document.createElement('h2');
					h1.textContent = movie.title;
					card.appendChild(h1);
					card.appendChild(poster);
				}

				card.id = movie.id;
				card.addEventListener("click", goToRelated);
				function goToRelated(evt)
				{
					var id = evt.currentTarget.id;
					if (movietype==1) currentURL = 'page=movie&' + 'id=' + id;
					else currentURL = 'page=tv&' + 'id=' + id;
					window.location.search = currentURL;
				}
				
				container.appendChild(card);
				i+=1;
			}
			
		}
		else
		{
			console.log ('whatthefuck');
		}
	}
	relatedRequest.send();

}