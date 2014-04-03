var app = angular.module('myApp', []);

app.run(function($rootScope){
  $rootScope.name = "Hello World";
})

app.config(['$routeProvider', function($routeProvider){
  $routeProvider
  .when('/home', {
    controller: 'HomeController',
    template: '<h2>We are home</h2>'
  })
  .otherwise({
    redirectTo: '/'
  });
}]);

app.controller("MyController", function($scope){
  $scope.person = {
    name: "Ari Lerner"
  }
})

app.controller("ParentController", function($scope){
  $scope.person = {
    greeted: false
  };
})

app.controller("ChildController", function($scope){
  $scope.sayHello = function() {
    $scope.person.greeted = true;
  }
})

app.controller("DemoController", function($scope){
  $scope.counter = 0;

  $scope.add = function(amount) {
    $scope.counter += amount;
  };

  $scope.subtract = function(amount) {
    $scope.counter -= amount;
  };
})

app.controller('HomeController', function($scope){

});

