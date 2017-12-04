local e = import "entities.jsonnet";

local main = [
  e.makePlatform({
    pos: [-16, -9],
    size: [32, 1]
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
    pos: [14, 6]
  }),
  e.makePlatform({
    pos: [-4, -7],
    size: [19, 1]
  }),
  e.makePlayer({
    pos: [-15, -8]
  }),
  e.makeExit({
    pos: [14, 7]
  })
];

local machinePlatforms = [
  e.makePlatform({
    pos: [-4, -8]
  })
] + [
  e.makePlatform({
    pos: [x, -8],
    size: [2, 1]
  }) for x in std.makeArray(3, function(x) 5 * x)
];

local machineBoxes = [
  e.makeBox({
    pos: [x, -8],
  }) for x in [-3, 2, 7, 12]
];

local machineButtons = [
  e.makeButton({
    id: i,
    pos: [-1 + i * 5, -8]
  }) for i in std.makeArray(4, function(x) x)
];

local machinePistons = [
  e.makeMovingPlatform({
    "in": 4,
    start: [-4, -8],
    end: [-3, -8],
    speed: 5,
    "waiting time": "forever"
  })
] + [
  e.makeMovingPlatform({
    "in": [i + 5, i],
    operator: "and",
    start: [i * 5 + 1, -8],
    end: [i * 5 + 2, -8],
    speed: 5,
    "waiting time": "forever"
  }) for i in std.makeArray(3, function(x) x)
];

local exitDoor = [
  e.makeDoor({
    "in": 3,
    pos: [13.5, 7]
  })
];

local keyButtons = [
  e.makeButton({
    id: 4,
    pos: [-11, -5]
  }),
  e.makeButton({
    id: 5,
    pos: [7, -3]
  }),
  e.makeButton({
    id: 6,
    pos: [9, 7]
  }),
  e.makeButton({
    id: 7,
    pos: [-9, 1]
  })
];

local row(start, y, size) = [
  e.makePlatform({
    pos: [start + offset, y]
  }) for offset in std.makeArray(size, function(i) i * 4)
];

local firstRow = row(-13, -8, 3);

local rows(startX, startY, width, height) = std.flattenArrays([
  local oddRow = r % 2 == 1;
  local x = if oddRow then startX + 2 else startX;
  local size = if oddRow then width - 1 else width;
  
  row(x, startY + r * 2, size)
  for r in std.makeArray(height, function(x) x)
]);

local stairs = firstRow + rows(-15, -6, 8, 7);

main
+ machinePlatforms
+ machineBoxes
+ machineButtons
+ machinePistons
+ exitDoor
+ keyButtons
+ stairs
