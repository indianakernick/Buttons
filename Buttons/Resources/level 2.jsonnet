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
  e.door.makeInPosSizeRot(0, [5.5, 1], [1, 2], 180),
  e.switch.makeIdPos(0, [-5, -1]),
  e.text.makePosText([0, 2], "Press space to toggle switches")
]
