local e = import "entities.jsonnet";

local main = [
  e.makePlatform({
    pos: [0, 0],
    size: [32, 1]
  }),
  e.makePlatform({
    pos: [1, 8],
    size: [30, 2]
  }),
  e.makePlatform({
    pos: [0, 17],
    size: [32, 1]
  }),
  e.makePlatform({
    pos: [0, 1],
    size: [1, 16]
  }),
  e.makePlatform({
    pos: [31, 1],
    size: [1, 16]
  }),
  e.makePlatform({
    pos: [29, 2],
    size: [3, 1]
  }),
  e.makePlayer({
    pos: [15, 4]
  }),
  e.makeExit({
    pos: [30, 1]
  }),
  e.makeBox({
    pos: [1, 14],
    size: [3, 3]
  })
];

local count = 26;
local pistonSpeed = 2;

local emitters = [
  e.makeLaserEmitter({
    id: x,
    on: true,
    start: [1 + x, 1],
    end: [1 + x, 7],
    orient: "up"
  }) for x in std.makeArray(count, function(x) x)
];

local detectors = [
  e.makeLaserDetector({
    id: count + x,
    emitter: x,
    pos: [1 + x, 7],
    orient: "down"
  }) for x in std.makeArray(count, function(x) x)
];

local movingPlatforms = [
  e.makeMovingPlatform({
    "in": count + x,
    operator: "not",
    start: [1 + x, 8],
    end: [1 + x, 10],
    size: [1, 2],
    speed: pistonSpeed,
    piston: true,
  }) for x in std.makeArray(count, function(x) x)
];

local exitDoor = [
  e.makeButton({
    id: 2 * count,
    pos: [28, 10]
  }),
  e.makeButton({
    id: 2 * count + 1,
    pos: [29, 10]
  }),
  e.makeDoor({
    "in": [2 * count, 2 * count + 1],
    operator: "or",
    pos: [29, 1]
  })
];

main
+ emitters
+ detectors
+ movingPlatforms
+ exitDoor
