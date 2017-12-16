local e = import "entities.jsonnet";

local digits = [
  [ //  0
    [1, 1, 1],
    [1, 0, 1],
    [1, 0, 1],
    [1, 0, 1],
    [1, 1, 1]
  ],
  [ //  1
    [0, 0, 1],
    [0, 0, 1],
    [0, 0, 1],
    [0, 0, 1],
    [0, 0, 1]
  ],
  [ //  2
    [1, 1, 1],
    [0, 0, 1],
    [1, 1, 1],
    [1, 0, 0],
    [1, 1, 1]
  ],
  [ //  3
    [1, 1, 1],
    [0, 0, 1],
    [1, 1, 1],
    [0, 0, 1],
    [1, 1, 1]
  ],
  [ //  4
    [1, 0, 1],
    [1, 0, 1],
    [1, 1, 1],
    [0, 0, 1],
    [0, 0, 1]
  ],
  [ //  5
    [1, 1, 1],
    [1, 0, 0],
    [1, 1, 1],
    [0, 0, 1],
    [1, 1, 1]
  ],
  [ //  6
    [1, 1, 1],
    [1, 0, 0],
    [1, 1, 1],
    [1, 0, 1],
    [1, 1, 1]
  ],
  [ //  7
    [1, 1, 1],
    [0, 0, 1],
    [0, 0, 1],
    [0, 0, 1],
    [0, 0, 1]
  ],
  [ //  8
    [1, 1, 1],
    [1, 0, 1],
    [1, 1, 1],
    [1, 0, 1],
    [1, 1, 1]
  ],
  [ //  9
    [1, 1, 1],
    [1, 0, 1],
    [1, 1, 1],
    [0, 0, 1],
    [1, 1, 1]
  ]
];

local topOrder    = [8, 4, 1, 9, 6];
local bottomOrder = [0, 7, 2, 5, 3];

//Blits digits in the given order onto a bitmap
local bitmap(order) = [
  [
    local digitIndex = order[std.floor(x / 4)];
    local row = digits[digitIndex][y];
    local colIndex = x % 4;

    if colIndex < 3 then row[colIndex] else 0

    for x in std.makeArray(std.length(order) * 4 - 1, function(x)x)
  ] for y in std.makeArray(5, function(x)x)
];

local isSolid(pixel) = (pixel == 0);

// I wanted to merge consecutive solid pixels into a single platform but I
// couldn't figure out how to do it in this language
local platforms2D(offx, offy, bitmap) = [
  [
    local pixel = bitmap[std.length(bitmap) - y - 1][x];

    if isSolid(pixel) then
      e.makePlatform({
        pos: [offx + x, offy + y]
      })
    else
      null

    for x in std.makeArray(std.length(bitmap[y]), function(x)x)
  ] for y in std.makeArray(std.length(bitmap), function(x)x)
];

local platforms(offx, offy, order) =
  std.filter(
    function(platform) (platform != null),
    std.flattenArrays(platforms2D(offx, offy, bitmap(order)))
  )
;

local switches(offx, offy, order) = [
  e.makeSwitch({
    id: order[i],
    pos: [offx + i * 4 + 1, offy]
  })
  for i in std.makeArray(std.length(order), function(x)x)
];

local repeatPlatforms(offx, offy, count) = [
  e.makePlatform({
    pos: [offx, offy + y],
    size: [4, 1]
  })
  for y in std.makeArray(count, function(y) y * 2)
];

local pistonSpeed = 10;

local repeatMachines(offx, offy, offi, count) = std.flattenArrays([
  local switchID = offi + i;
  local thisButtonID = 10 + switchID;
  local prevButtonID = thisButtonID - 1;
  local x = offx;
  local y = offy + i * 2;

  [
    e.makeButton({
      id: thisButtonID,
      pos: [x, y]
    }),
    e.makeDoor({
      pos: [x + 1, y],
      "in": prevButtonID
    }),
    e.makeBox({
      pos: [x + 3, y]
    }),
    e.makeMovingPlatform({
      start: [x + 4, y],
      end: [x + 3, y],
      speed: pistonSpeed,
      piston: true,
      "in": switchID
    })
  ] for i in std.makeArray(count, function(i)i)
]);

local firstMachine(x, y) = [
  e.makeButton({
    id: 10,
    pos: [x, y]
  }),
  e.makeBox({
    pos: [x + 3, y]
  }),
  e.makeMovingPlatform({
    start: [x + 4, y],
    end: [x + 3, y],
    speed: pistonSpeed,
    piston: true,
    "in": 0
  })
];

platforms(1, 11, topOrder)
+ platforms(1, 3, bottomOrder)
+ switches(1, 9, topOrder)
+ switches(1, 1, bottomOrder)
+ repeatPlatforms(25, 4, 7)
+ repeatPlatforms(21, 11, 3)
+ firstMachine(25, 3)
+ repeatMachines(25, 5, 1, 6)
+ repeatMachines(21, 12, 7, 3)
+ [
  //above top
  e.makePlatform({
    pos: [1, 16],
    size: [20, 2]
  }),
  //below top
  e.makePlatform({
    pos: [1, 10],
    size: [24, 1]
  }),
  //above bottom
  e.makePlatform({
    pos: [1, 8],
    size: [19, 1]
  }),
  //below bottom
  e.makePlatform({
    pos: [1, 2],
    size: [19, 1]
  }),
  //left top and bottom
  e.makePlatform({
    pos: [0, 1],
    size: [1, 17]
  }),
  //right bottom
  e.makePlatform({
    pos: [20, 2],
    size: [1, 7]
  }),
  //right top
  e.makePlatform({
    pos: [20, 10],
    size: [1, 6]
  }),
  //bottom floor
  e.makePlatform({
    pos: [0, 0],
    size: [32, 1]
  }),

  e.makePlatform({
    pos: [23, 2],
    size: [2, 8]
  }),
  e.makePlatform({
    pos: [21, 17],
    size: [11, 1]
  }),
  e.makePlatform({
    pos: [31, 1],
    size: [1, 16]
  }),
  e.makePlatform({
    pos: [29, 2],
    size: [1, 15]
  }),
  e.makePlatform({
    pos: [25, 2],
    size: [4, 1]
  }),

  e.makeMovingPlatform({
    start: [21, 0],
    end: [21, 8],
    size: [2, 1],
    speed: 0.2,
    "waiting time": 2,
    on: true
  }),
  e.makeMovingPlatform({
    start: [30, 0],
    end: [30, 15],
    speed: 0.2,
    "waiting time": 3,
    "in": 19
  }),

  e.makePlayer({
    pos: [1, 1]
  }),
  e.makeExit({
    pos: [30, 16]
  })
]
