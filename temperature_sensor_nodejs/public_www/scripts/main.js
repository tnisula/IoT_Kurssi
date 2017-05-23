var app = angular.module("TempApp",["Controllers","ngRoute"]);

app.config(['$locationProvider', function($locationProvider) {
	$locationProvider.hashPrefix('');
}]);

app.config(["$routeProvider",
	function($routeProvider) {
		$routeProvider.
			when('/', { 
				templateUrl:'views/templist.html',
				controller:'TempController'
			}).
			when('/listpage', {
				templateUrl:'views/templist.html',
				controller:'TempController'
			}).when('/addpage', {
				templateUrl:'views/newtemp.html',
				controller:'AddController'
			}).otherwise({
				redirectTo:'/'
			});		


}]);
