local e = import "entities.jsonnet";

[
  e.makePlatform({
    pos: [-16, -9],
    size: [32, 8]
  }),
  e.makePlatform({
    pos: [-16, 1],
    size: [32, 8]
  }),
  e.makePlatform({
    pos: [-16, -1],
    size: [1, 2]
  }),
  e.makePlatform({
    pos: [15, -1],
    size: [1, 2]
  }),
  e.makePlayer({
    pos: [-15, -1]
  }),
  e.makeExit({
    pos: [14, -1]
  }),
  e.text.makePosText([0, 2], "Press A and D or left and right to move")
]
