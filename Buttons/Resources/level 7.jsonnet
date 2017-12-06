local e = import "entities.jsonnet";

local main = [
  e.makePlatform({
    pos: [0, 0],
    size: [32, 1]
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
    pos: [30, 15]
  }),
  e.makePlatform({
    pos: [12, 2],
    size: [19, 1]
  }),
  e.makePlayer({
    pos: [1, 1]
  }),
  e.makeExit({
    pos: [30, 16]
  })
];

local machinePlatforms = [
  e.makePlatform({
    pos: [12, 1]
  })
] + [
  e.makePlatform({
    pos: [x, 1],
    size: [2, 1]
  }) for x in std.makeArray(3, function(x) 5 * x + 16)
];

local machineBoxes = [
  e.makeBox({
    pos: [x, 1],
  }) for x in [13, 18, 23, 28]
];

local machineButtons = [
  e.makeButton({
    id: i,
    pos: [15 + i * 5, 1]
  }) for i in std.makeArray(4, function(x) x)
];

local machinePistons = [
  e.makeMovingPlatform({
    "in": 4,
    start: [12, 1],
    end: [13, 1],
    speed: 5,
    "waiting time": "piston"
  })
] + [
  e.makeMovingPlatform({
    "in": [i + 5, i],
    operator: "and",
    start: [i * 5 + 17, 1],
    end: [i * 5 + 18, 1],
    speed: 5,
    "waiting time": "piston"
  }) for i in std.makeArray(3, function(x) x)
];

local exitDoor = [
  e.makeDoor({
    "in": 3,
    pos: [29.5, 16]
  })
];

local keyButtons = [
  e.makeButton({
    id: 4,
    pos: [5, 4]
  }),
  e.makeButton({
    id: 5,
    pos: [23, 6]
  }),
  e.makeButton({
    id: 6,
    pos: [25, 16]
  }),
  e.makeButton({
    id: 7,
    pos: [7, 10]
  })
];

local row(start, y, size) = [
  e.makePlatform({
    pos: [start + offset, y]
  }) for offset in std.makeArray(size, function(i) i * 4)
];

local firstRow = row(3, 1, 3);

local rows(startX, startY, width, height) = std.flattenArrays([
  local oddRow = r % 2 == 1;
  local x = if oddRow then startX + 2 else startX;
  local size = if oddRow then width - 1 else width;

  row(x, startY + r * 2, size)
  for r in std.makeArray(height, function(x) x)
]);

local stairs = firstRow + rows(1, 3, 8, 7);

main
+ machinePlatforms
+ machineBoxes
+ machineButtons
+ machinePistons
+ exitDoor
+ keyButtons
+ stairs


/*
function shift(str, key) {
  let string = "";
  let lastIndex = 0;
  for (let index = str.indexOf(key); index != -1; index = str.indexOf(key, index + 1)) {
    let open = str.indexOf('[', index);
    let close = str.indexOf(']', open);
    string += str.slice(lastIndex, open);
    try {
      let pos = eval(str.slice(open, close + 1));
      pos[0] += 16;
      pos[1] += 9;
      string += "[" + pos[0] + ", " + pos[1] + "]";
    } catch (e) {
      string += str.slice(open, close + 1);
      console.log("Missed: " + str.slice(index, index + 50));
    }
    lastIndex = close + 1;
  }
  string += str.slice(lastIndex);
  return string;
}

function shiftAll(str) {
  return shift(shift(shift(str, "pos:"), "start:"), "end:");
}
*/
