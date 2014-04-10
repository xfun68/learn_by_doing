var app = angular.module('myApp', []);

app.controller('MainCtrl', ['$scope', function($scope){
  $scope.cars = [
    {
      id: 1,
      name: 'Car1'
    },
    {
      id: 2,
      name: 'Car2'
    },
    {
      id: 3,
      name: 'Car3'
    }
  ];
}]);

app.directive('carShow', function(){
  return {
    restrict: 'A',
    scope: {
      cars: '='
    },
    templateUrl: 'cars-table.html'
  };
});

