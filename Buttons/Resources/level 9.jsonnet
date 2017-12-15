local e = import "entities.jsonnet";

local platforms = [
  //outer border
  e.makePlatform({
    pos: [0, 0],
    size: [32, 1]
  }),
  e.makePlatform({
    pos: [0, 1],
    size: [1, 16]
  }),
  e.makePlatform({
    pos: [0, 17],
    size: [32, 1]
  }),
  e.makePlatform({
    pos: [31, 1],
    size: [1, 16]
  }),
  
  //combo lock
  e.makePlatform({
    pos: [1, 15],
    size: [22, 1]
  }),
  e.makePlatform({
    pos: [1, 13],
    size: [23, 1]
  }),
  e.makePlatform({
    pos: [1, 16],
    size: [2, 1]
  }),
  e.makePlatform({
    pos: [12, 16]
  }),
  e.makePlatform({
    pos: [22, 16]
  }),
  
  //key 2
  e.makePlatform({
    pos: [23, 7],
    size: [3, 1]
  }),
  e.makePlatform({
    pos: [22, 5],
    size: [5, 1]
  }),
  
  //key 0
  e.makePlatform({
    pos: [3, 8],
    size: [12, 1]
  }),
  e.makePlatform({
    pos: [9, 9]
  }),
  e.makePlatform({
    pos: [7, 10],
    size: [3, 1]
  }),
  
  //key 5
  e.makePlatform({
    pos: [3, 6],
    size: [1, 2]
  }),
  e.makePlatform({
    pos: [3, 5],
    size: [4, 1]
  }),
  
  //key 3
  e.makePlatform({
    pos: [10, 5],
    size: [4, 1]
  }),
  
  //key 1
  e.makePlatform({
    pos: [14, 1],
    size: [1, 7]
  }),
  e.makePlatform({
    pos: [17, 3],
    size: [1, 6]
  }),
  e.makePlatform({
    pos: [17, 2],
    size: [4, 1]
  }),
  e.makePlatform({
    pos: [20, 1]
  }),
  
  //exit
  e.makePlatform({
    pos: [7, 2],
    size: [3, 1]
  }),
  e.makePlatform({
    pos: [9, 1]
  })
];

local makeStairs(start_x, start_y, count) = [
  e.makePlatform({
    pos: [start_x, start_y + offsetY]
  }) for offsetY in std.makeArray(count, function(y) y * 4)
];

local stairs =
  makeStairs(30, 1, 4) +
  makeStairs(28, 3, 4) +
  makeStairs(26, 9, 2) +
[
  e.makePlatform({
    pos: [26, 1]
  }),
  e.makePlatform({
    pos: [24, 3]
  }),
  e.makePlatform({
    pos: [22, 1]
  }),
  e.makePlatform({
    pos: [20, 3]
  }),
  e.makePlatform({
    pos: [18, 5]
  }),
  e.makePlatform({
    pos: [20, 7]
  }),
  e.makePlatform({
    pos: [22, 9]
  }),
  e.makePlatform({
    pos: [18, 9]
  })
];

local keys = [
  e.makeKey({
    index: 0,
    pos: [8, 9]
  }),
  e.makeKey({
    index: 1,
    pos: [19, 1]
  }),
  e.makeKey({
    index: 2,
    pos: [24, 6]
  }),
  e.makeKey({
    //Is this a sign?
    index: 3,
    pos: [13, 6]
  }),
  e.makeKey({
    index: 4,
    pos: [1, 14]
  }),
  e.makeKey({
    index: 5,
    pos: [4, 6]
  }),
  e.makeKey({
    index: 6,
    pos: [28, 16]
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
    pos: [6, 1]
  }),
  e.makeLock({
    id: 1,
    index: 1,
    pos: [6, 9]
  }),
  e.makeLock({
    id: 2,
    index: 2,
    pos: [17, 1]
  }),
  e.makeLock({
    id: 3,
    index: 3,
    pos: [24, 8]
  }),
  e.makeLock({
    id: 4,
    index: 4,
    //between 5 and 3 lies 4
    pos: [11, 6]
  }),
  e.makeLock({
    id: 5,
    index: 5,
    pos: [23, 14]
  }),
  e.makeLock({
    id: 6,
    index: 6,
    pos: [6, 6]
  })
];

local doors = [
  e.makeDoor({
    "in": 0,
    pos: [7, 1]
  }),
  e.makeDoor({
    "in": 1,
    pos: [7, 9]
  }),
  e.makeDoor({
    "in": 2,
    pos: [18, 1]
  }),
  e.makeDoor({
    "in": 3,
    pos: [23, 6]
  }),
  e.makeDoor({
    "in": 3,
    pos: [25, 6]
  }),
  e.makeDoor({
    "in": 4,
    pos: [12, 6],
    height: 2
  }),
  e.makeDoor({
    "in": 5,
    pos: [22, 14]
  }),
  e.makeDoor({
    "in": 6,
    pos: [5, 6],
    height: 2
  }),
  e.makeDoor({
    "in": 8,
    pos: [15, 8],
    height: 2,
    orient: "right"
  }),
  e.makeDoor({
    "in": 19,
    pos: [12, 14]
  }),
  e.makeDoor({
    "in": 21,
    pos: [2, 14]
  }),
  
  /*left combo lock
  
  0   0 AND 1
  1   1 XOR 3
  2   2 NOR 3
  3   0 OR 2
  */
  e.makeDoor({
    "in": [10, 11],
    operator: "and",
    pos: [4, 16]
  }),
  e.makeDoor({
    "in": [11, 13],
    operator: "xor",
    pos: [6, 16]
  }),
  e.makeDoor({
    "in": [12, 13],
    operator: "nor",
    pos: [8, 16]
  }),
  e.makeDoor({
    "in": [10, 12],
    operator: "or",
    pos: [10, 16]
  }),
  
  /*right combo lock
  
  0   1 XOR 2
  1   0 NOR 2
  2   1 XNOR 3
  3   0 NAND 3
  */
  e.makeDoor({
    "in": [15, 16],
    operator: "xor",
    pos: [14, 16]
  }),
  e.makeDoor({
    "in": [14, 16],
    operator: "nor",
    pos: [16, 16]
  }),
  e.makeDoor({
    "in": [15, 17],
    operator: "xnor",
    pos: [18, 16]
  }),
  e.makeDoor({
    "in": [14, 17],
    operator: "nand",
    pos: [20, 16]
  })
];

local makeSwitchRow(start_x, start_id) = [
  e.makeSwitch({
    id: start_id + i,
    pos: [start_x + i * 2, 14]
  }) for i in std.makeArray(4, function(x) x)
];

local switches = [
  e.makeSwitch({
    id: 7,
    pos: [3, 1]
  }),
  e.makeSwitch({
    id: 8,
    pos: [10, 6]
  })
] + makeSwitchRow(4, 10)
  + makeSwitchRow(14, 14);

local misc = [
  e.makePlayer({
    pos: [1, 1]
  }),
  e.makeExit({
    pos: [8, 1]
  }),
  e.makeBox({
    pos: [8, 3]
  }),
  e.makeButton({
    id: 9,
    pos: [13, 1]
  })
];

local movingPlatforms = [
  e.makeMovingPlatform({
    "in": 7,
    start: [1, 0],
    end: [1, 8],
    size: [2, 1],
    speed: 0.1,
    "waiting time": 2
  }),
  e.makeMovingPlatform({
    "in": 9,
    start: [15, 0],
    end: [15, 7],
    size: [2, 1],
    speed: 0.1,
    "waiting time": 2
  })
];

local lasers = [
  e.makeLaserEmitter({
    id: 18,
    "in": 5,
    start: [21, 16],
    end: [13, 16],
    orient: "left"
  }),
  e.makeLaserDetector({
    id: 19,
    emitter: 18,
    pos: [13, 16],
    orient: "right"
  }),
  e.makeLaserEmitter({
    id: 20,
    "in": 19,
    start: [11, 16],
    end: [3, 16],
    orient: "left"
  }),
  e.makeLaserDetector({
    id: 21,
    emitter: 20,
    pos: [3, 16],
    orient: "right"
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
