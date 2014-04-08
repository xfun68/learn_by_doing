app = angular.module("myApp", []);

app.config(['$routeProvider', function($routeProvider){
  $routeProvider
  .when('/',{
    controller: 'WeatherController',
    templateUrl: '/weather.html'
  })
  .otherwise({redirectTo: '/app.html'});
}]);

app.controller('WeatherController', ['$scope', function($scope){
  $scope.city = '';
}]);

app.directive('ngSparkline', function(){
  return {
    restrict: 'A',
    require: '^ngModel',
    template: '<div class="sparkline"><h4>Weather for {{ngModel}}</h4></div>'
  };
});

