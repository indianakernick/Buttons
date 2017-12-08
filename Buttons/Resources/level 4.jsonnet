local e = import "entities.jsonnet";

[
  e.makePlatform({
    pos: [0, 0],
    size: [32, 4]
  }),
  e.makePlatform({
    pos: [1, 8],
    size: [30, 2]
  }),
  e.makePlatform({
    pos: [0, 14],
    size: [32, 4]
  }),
  e.makePlatform({
    pos: [0, 4],
    size: [1, 10]
  }),
  e.makePlatform({
    pos: [31, 4],
    size: [1, 10]
  }),
  e.makePlayer({
    pos: [1, 4]
  }),
  e.makeExit({
    pos: [30, 4]
  }),
  e.makeDoor({
    "in": 5,
    pos: [25, 4],
    height: 4
  }),
  e.makeSwitch({
    id: 0,
    pos: [11, 4]
  }),
  e.makeSwitch({
    id: 1,
    pos: [14, 4]
  }),
  e.makeSwitch({
    id: 2,
    pos: [17, 4]
  }),
  e.makeSwitch({
    id: 3,
    pos: [20, 4]
  }),
  e.makeLaserEmitter({
    id: 4,
    "on": true,
    start: [1, 11.5],
    end: [30, 11.5],
    orient: "right"
  }),
  e.makeLaserDetector({
    id: 5,
    emitter: 4,
    pos: [30, 11.5],
    orient: "left"
  }),
  e.makeDoor({
    "in": [0, 1],
    operator: "or",
    pos: [5, 10],
    height: 4
  }),
  e.makeDoor({
    "in": [0, 2],
    operator: "xor",
    pos: [12, 10],
    height: 4
  }),
  e.makeDoor({
    "in": 2,
    pos: [19, 10],
    height: 4
  }),
  e.makeDoor({
    "in": 3,
    operator: "not",
    pos: [26, 10],
    height: 4
  })
]
