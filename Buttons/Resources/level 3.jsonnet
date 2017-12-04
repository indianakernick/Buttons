local e = import "entities.jsonnet";

[
  e.makePlatform({
    pos: [-16, -9],
    size: [32, 7]
  }),
  e.makePlatform({
    pos: [-16, 2],
    size: [32, 7]
  }),
  e.makePlatform({
    pos: [-16, -2],
    size: [1, 4]
  }),
  e.makePlatform({
    pos: [15, -2],
    size: [1, 4]
  }),
  e.makePlayer({
    pos: [-10, -2]
  }),
  e.makeExit({
    pos: [14, -2]
  }),
  e.makeBox({
    pos: [-13, -2]
  }),
  e.makeButton({
    id: 0,
    pos: [-2, -2]
  }),
  e.switch.makeIdPos(1, [1, -2]),
  e.door.makeInPosSizeRot(1, [5.5, 2], [1, 4], 180),
  e.door.makeInPosSizeRot(0, [8.5, 2], [1, 4], 180)
]
