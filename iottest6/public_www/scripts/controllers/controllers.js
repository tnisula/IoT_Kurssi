var module = angular.module("Controllers",[]);

module.controller("TempController", function($scope,$http) {
	$scope.getTemps = function() {
			$http({
				method: "GET",
				url:"api/temps",
				headers:{"Content-type":"application/json"}
			}).then(function(data) {
				console.log(data);
				console.log(data.data);
				$scope.temps = data.data;
			});
	};
});
	
module.controller("AddController", function($scope,$http){					
	$scope.addTemp = function() {
			$http({
				method: "POST",
				url:"api/temps",
				data:{"dateandtime":$scope.newtemp.dateandtime,
				      "value":$scope.newtemp.value},
				headers:{"Content-type":"application/json"}
			}).then(function(data) {
			   	$scope.newtemp.dateandtime="";
				$scope.newtemp.value=0;				
			});
	};
});
