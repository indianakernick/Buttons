local e = import "entities.jsonnet";

[
  e.makePlatform({
    pos: [0, 0],
    size: [32, 7]
  }),
  e.makePlatform({
    pos: [0, 11],
    size: [32, 7]
  }),
  e.makePlatform({
    pos: [0, 7],
    size: [1, 4]
  }),
  e.makePlatform({
    pos: [31, 7],
    size: [1, 4]
  }),
  e.makePlayer({
    pos: [6, 7]
  }),
  e.makeExit({
    pos: [30, 7]
  }),
  e.makeBox({
    pos: [3, 7]
  }),
  e.makeButton({
    id: 0,
    pos: [14, 7]
  }),
  e.makeSwitch({
    id: 1,
    pos: [17, 7]
  }),
  e.makeDoor({
    "in": 1,
    pos: [21, 10],
    height: 4,
    orient: "down"
  }),
  e.makeDoor({
    "in": 0,
    pos: [24, 10],
    height: 4,
    orient: "down"
  })
]
