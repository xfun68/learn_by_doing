var app = angular.module('myApp', ['ui.bootstrap']);

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
    },
    {
      id: 4,
      name: 'Car4'
    },
    {
      id: 5,
      name: 'Car5'
    },
    {
      id: 6,
      name: 'Car6'
    },
    {
      id: 7,
      name: 'Car7'
    },
    {
      id: 8,
      name: 'Car8'
    },
    {
      id: 9,
      name: 'Car9'
    }
  ];
}]);

app.directive('carShow', function(){
  return {
    restrict: 'A',
    scope: {
      cars: '='
    },
    templateUrl: 'cars-table.html',
    link: function($scope){
      $scope.totalItems = $scope.cars.length;
      $scope.currentPage = 1;
      $scope.itemsPerPage = 3;
    }
  };
});

