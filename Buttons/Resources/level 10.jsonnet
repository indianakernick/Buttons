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

local keys = [
  e.makeKey({
    index: 0,
    pos: [-10, 0]
  }),
  e.makeKey({
    index: 1,
    pos: [3, -8]
  })
];

platforms + keys + [
  e.makePlayer({
    pos: [-15, -8]
  }),
  e.makeExit({
    pos: [-8, -8]
  }),
  e.makeLock({
    id: 0,
    index: 0,
    pos: [-11, -8]
  }),
  e.makeDoor({
    "in": 0,
    pos: [-8.5, -8]
  }),
  e.makeSwitch({
    id: 10,
    pos: [-13, -8]
  }),
  e.makeMovingPlatform({
    "in": 10,
    start: [-15, -9],
    end: [-15, -1],
    size: [2, 1],
    speed: 0.1,
    "waiting time": 2.0
  }),
  e.makeLock({
    id: 1,
    index: 1,
    pos: [-13, 0]
  }),
  e.makeDoor({
    "in": 1,
    pos: [-10.5, 0]
  })
]
