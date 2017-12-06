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

local areaWidth = 26;
local count = areaWidth;
local scale = areaWidth / count;
local pistonSpeed = 2;

local emitters = [
  e.makeLaserEmitter({
    id: i,
    on: true,
    start: [1 + scale / 2 + i * scale, 1],
    end: [1 + scale / 2 + i * scale, 8],
    size: [scale, scale]
  }) for i in std.makeArray(count, function(x) x)
];

local detectors = [
  e.makeLaserDetector({
    id: count + i,
    emitter: i,
    pos: [1 + scale / 2 + i * scale, 8],
    size: [scale, scale],
    rotation: 180
  }) for i in std.makeArray(count, function(x) x)
];

local movingPlatforms = [
  e.makeMovingPlatform({
    "in": count + i,
    operator: "not",
    start: [1 + i * scale, 8],
    end: [1 + i * scale, 10],
    size: [scale, 2],
    speed: pistonSpeed,
    "waiting time": "piston"
  }) for i in std.makeArray(count, function(x) x)
];

local exitDoor = [
  e.makeButton({
    id: 2 * count,
    pos: [28, 10],
    size: [2, 2]
  }),
  e.makeDoor({
    "in": 2 * count,
    pos: [29, 1]
  })
];

main + emitters + detectors + movingPlatforms + exitDoor
