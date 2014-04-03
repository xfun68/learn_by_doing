var app = angular.module('myApp', [])

var apiKey = 'MDEzNDkzNjEyMDEzOTY0MjA0MjhjMTY4OA001';
var nprUrl = 'http://api.npr.org/query?id=61&fields=relatedLink,title,byline,text,audio,image,pullQuote,all&output=JSON';

app.directive('nprLink', function() {
  return {
    restrict: 'EA',
    require: ['^ngModel'],
    replace: true,
    scope: {
      ngModel: '=',
      player: '='
    },
    templateUrl: '/views/nprListItem.html',
    link: function(scope, ele, attr) {
      scope.duration = scope.ngModel.audio[0].duration.$text;
    }
  }
});

app.factory('audio', ['$document', function($document){
  var audio = $document[0].createElement('audio');
  return audio;
}]);

app.factory('player', ['audio', '$rootScope', function(audio, $rootScope){
  var player = {
    playing: false,
    current: null,
    ready: false,

    play: function(program) {
      if (player.playing) player.stop();
      player.current = program;
      var url = program.audio[0].format.mp4.$text;
      audio.src = url;
      audio.play();
      player.playing = true;
    },

    stop: function() {
      if (player.playing) {
        audio.pause();
        player.ready = player.playing = false;
        player.current = null;
      }
    },

    currentTime: function() {
      return audio.currentTime;
    },

    currentDuration: function() {
      return parseInt(audio.duration);
    }
  };

  audio.addEventListener('ended', function(){
    $rootScope.$apply(player.stop());
  });

  audio.addEventListener('timeupdate', function(evt){
    $rootScope.$apply(function(){
      player.progress = player.currentTime();
      player.progress_percent = player.progress / player.currentDuration();
    });
  });

  audio.addEventListener('canplay', function(evt){
    $rootScope.$apply(function(){
      player.ready = true;
    });
  });

  return player;
}]);

app.controller('PlayerController', ['$scope', '$http', 'player', function($scope, $http, player){
  $scope.player = player;

  $scope.play = function(program) {
    $scope.player.play(program);
  };

  $scope.stop = function() {
    $scope.player.stop();
  };

  $http({
    method: 'JSONP',
    url: nprUrl + '&apiKey=' + apiKey + '&callback=JSON_CALLBACK'
  }).success(function(data, status){
    $scope.programs = data.list.story;
  }).error(function(data, status){
  });
}]);

app.controller('RelatedController', ['$scope', function($scope){
}]);

