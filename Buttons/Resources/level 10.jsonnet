local e = import "entities.jsonnet";

local platforms = [
  //outer border
  e.makePlatform({
    pos: [-16, -9],
    size: [32, 1]
  }),
  e.makePlatform({
    pos: [-16, -8],
    size: [1, 16]
  }),
  e.makePlatform({
    pos: [-16, 8],
    size: [32, 1]
  }),
  e.makePlatform({
    pos: [15, -8],
    size: [1, 16]
  }),
  
  //combo lock
  e.makePlatform({
    pos: [-15, 6],
    size: [20, 1]
  }),
  e.makePlatform({
    pos: [-15, 4],
    size: [21, 1]
  }),
  e.makePlatform({
    pos: [-6, 7]
  }),
  e.makePlatform({
    pos: [4, 7]
  }),
  
  //key 4
  e.makePlatform({
    pos: [13, 6],
    size: [2, 1]
  }),
  
  //key 2
  e.makePlatform({
    pos: [5, -3],
    size: [3, 1]
  }),
  e.makePlatform({
    pos: [5, -5],
    size: [3, 1]
  }),
  
  //key 0
  e.makePlatform({
    pos: [-13, -1],
    size: [12, 1]
  }),
  e.makePlatform({
    pos: [-9, 0]
  }),
  e.makePlatform({
    pos: [-11, 1],
    size: [3, 1]
  }),
  
  //key 5
  e.makePlatform({
    pos: [-13, -3],
    size: [1, 2]
  }),
  e.makePlatform({
    pos: [-13, -4],
    size: [4, 1]
  }),
  
  //key 3
  e.makePlatform({
    pos: [-6, -4],
    size: [4, 1]
  }),
  
  //key 1
  e.makePlatform({
    pos: [-2, -8],
    size: [1, 7]
  }),
  e.makePlatform({
    pos: [1, -6],
    size: [1, 6]
  }),
  e.makePlatform({
    pos: [1, -7],
    size: [4, 1]
  }),
  e.makePlatform({
    pos: [4, -8]
  }),
  
  //exit
  e.makePlatform({
    pos: [-9, -7],
    size: [3, 1]
  }),
  e.makePlatform({
    pos: [-7, -8]
  })
];

local makeStairs(start_x, start_y, count) = [
  e.makePlatform({
    pos: [start_x, start_y + offsetY]
  }) for offsetY in std.makeArray(count, function(y) y * 4)
];

local stairs =
  makeStairs(12, -8, 4) +
  makeStairs(10, -6, 4) +
  makeStairs(8, 0, 2) +
  [
    e.makePlatform({
      pos: [4, 0]
    })
  ];

local keys = [
  e.makeKey({
    index: 0,
    pos: [-10, 0]
  }),
  e.makeKey({
    index: 1,
    pos: [3, -8]
  }),
  e.makeKey({
    index: 2,
    //6 minus 4 is 2
    pos: [6, -4]
  }),
  e.makeKey({
    //Is this a sign?
    index: 3,
    pos: [-3, -3]
  }),
  e.makeKey({
    index: 4,
    pos: [14, 7]
  }),
  e.makeKey({
    index: 5,
    pos: [-12, -3]
  }),
  e.makeKey({
    index: 6,
    pos: [10, 7]
  })
];

/*

ID ALLOCATION

0-6      Locks
7        Left switch
8        Right switch
9        Button
10-17    Combo lock switches
18       Right laser emitter
19       Right laser detector
20       Left laser emitter
21       Left laser detector

*/

local locks = [
  e.makeLock({
    id: 0,
    index: 0,
    pos: [-11, -8]
  }),
  e.makeLock({
    id: 1,
    index: 1,
    pos: [-13, 0]
  }),
  e.makeLock({
    id: 2,
    index: 2,
    pos: [1, -8]
  }),
  e.makeLock({
    id: 3,
    index: 3,
    //6 divided by 2 is 3
    pos: [6, -2]
  }),
  e.makeLock({
    id: 4,
    index: 4,
    //between 5 and 3 lies 4
    pos: [-5, -3]
  }),
  e.makeLock({
    //I swear this is completly accidental
    id: 5,
    index: 5,
    pos: [5, 5]
  }),
  e.makeLock({
    id: 6,
    index: 6,
    pos: [-10, -3]
  })
];

local doors = [
  e.makeDoor({
    "in": 0,
    pos: [-8.5, -8]
  }),
  e.makeDoor({
    "in": 1,
    pos: [-10.5, 0]
  }),
  e.makeDoor({
    "in": 2,
    pos: [2.5, -8]
  }),
  e.makeDoor({
    "in": 3,
    pos: [5.5, -4]
  }),
  e.makeDoor({
    "in": 3,
    pos: [7.5, -4]
  }),
  e.makeDoor({
    "in": 4,
    pos: [-3.5, -3],
    size: [1, 2]
  }),
  e.makeDoor({
    "in": 5,
    pos: [4.5, 5]
  }),
  e.makeDoor({
    "in": 6,
    pos: [-10.5, -3],
    size: [1, 2]
  }),
  e.makeDoor({
    "in": 8,
    pos: [-1, -0.5],
    size: [1, 2],
    rotation: -90
  }),
  e.makeDoor({
    "in": 19,
    pos: [-5.5, 5]
  }),
  e.makeDoor({
    "in": 21,
    pos: [13.5, 7]
  })
];

local makeSwitchRow(start_x, start_id) = [
  e.makeSwitch({
    id: start_id + i,
    pos: [start_x + i * 2, 5]
  }) for i in std.makeArray(4, function(x) x)
];

local switches = [
  e.makeSwitch({
    id: 7,
    pos: [-13, -8]
  }),
  e.makeSwitch({
    id: 8,
    pos: [-6, -3]
  })
] + makeSwitchRow(-14, 10)
  + makeSwitchRow(-4, 14);

local misc = [
  e.makePlayer({
    pos: [-15, -8]
  }),
  e.makeExit({
    pos: [-8, -8]
  }),
  e.makeBox({
    pos: [-8, -6]
  }),
  e.makeButton({
    id: 9,
    pos: [-6, -8]
  })
];

local movingPlatforms = [
  e.makeMovingPlatform({
    "in": 7,
    start: [-15, -9],
    end: [-15, -1],
    size: [2, 1],
    speed: 0.1,
    "waiting time": 2
  }),
  e.makeMovingPlatform({
    "in": 9,
    start: [-1, -9],
    end: [-1, -2],
    size: [2, 1],
    speed: 0.1,
    "waiting time": 2
  })
];

local lasers = [
  e.makeLaserEmitter({
    id: 18,
    "in": 5,
    start: [4, 7.5],
    end: [-5, 7.5],
    rotation: 90
  }),
  e.makeLaserDetector({
    id: 19,
    emitter: 18,
    pos: [-5, 7.5],
    rotation: -90
  }),
  e.makeLaserEmitter({
    id: 20,
    "in": 19,
    start: [-6, 7.5],
    end: [-15, 7.5],
    rotation: 90
  }),
  e.makeLaserDetector({
    id: 21,
    emitter: 20,
    pos: [-15, 7.5],
    rotation: -90
  })
];

platforms +
stairs +
keys +
locks +
doors +
switches +
misc +
movingPlatforms +
lasers
