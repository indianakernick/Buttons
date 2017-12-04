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
  e.makeSwitch({
    id: 0,
    pos: [-5, -1]
  }),
  e.makeText({
    pos: [0, 2],
    text: "Press space to toggle switches"
  })
]
