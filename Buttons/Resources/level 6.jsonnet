local e = import "entities.jsonnet";

local main = [
  e.makePlatform({
    pos: [-16, -9],
    size: [32, 1]
  }),
  e.makePlatform({
    pos: [-15, -1],
    size: [30, 2]
  }),
  e.makePlatform({
    pos: [-16, 8],
    size: [32, 1]
  }),
  e.makePlatform({
    pos: [-16, -8],
    size: [1, 16]
  }),
  e.makePlatform({
    pos: [15, -8],
    size: [1, 16]
  }),
  e.makePlatform({
    pos: [13, -7],
    size: [3, 1]
  }),
  e.makePlayer({
    pos: [-1, -5]
  }),
  e.makeExit({
    pos: [14, -8]
  }),
  e.makeBox({
    pos: [-15, 5],
    size: [3, 3]
  })
];

local areaWidth = 26;
local count = areaWidth;
local scale = areaWidth / count;
local pistonSpeed = 3;

local emitters = [
  e.makeLaserEmitter({
    id: i,
    on: true,
    start: [-15 + scale / 2 + i * scale, -8],
    end: [-15 + scale / 2 + i * scale, -1],
    size: [scale, scale]
  }) for i in std.makeArray(count, function(x) x)
];

local detectors = [
  e.makeLaserDetector({
    id: count + i,
    emitter: i,
    pos: [-15 + scale / 2 + i * scale, -1],
    size: [scale, scale],
    rotation: 180
  }) for i in std.makeArray(count, function(x) x)
];

local movingPlatforms = [
  e.makeMovingPlatform({
    "in": count + i,
    operator: "not",
    start: [-15 + i * scale, -1],
    end: [-15 + i * scale, 1],
    size: [scale, 2],
    speed: pistonSpeed,
    "waiting time": "forever"
  }) for i in std.makeArray(count, function(x) x)
];

local exitDoor = [
  e.makeButton({
    id: 2 * count,
    pos: [12, 1],
    size: [2, 2]
  }),
  e.makeDoor({
    "in": 2 * count,
    pos: [13.5, -8]
  })
];

main + emitters + detectors + movingPlatforms + exitDoor
