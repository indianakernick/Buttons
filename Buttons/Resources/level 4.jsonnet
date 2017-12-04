local e = import "entities.jsonnet";

[
  e.makePlatform({
    pos: [-16, -9],
    size: [32, 4]
  }),
  e.makePlatform({
    pos: [-15, -1],
    size: [30, 2]
  }),
  e.makePlatform({
    pos: [-16, 5],
    size: [32, 4]
  }),
  e.makePlatform({
    pos: [-16, -5],
    size: [1, 10]
  }),
  e.makePlatform({
    pos: [15, -5],
    size: [1, 10]
  }),
  e.makePlayer({
    pos: [-15, -5]
  }),
  e.makeExit({
    pos: [14, -5]
  }),
  e.makeDoor({
    "in": 5,
    pos: [9.5, -5],
    size: [1, 4]
  }),
  e.makeSwitch({
    id: 0,
    pos: [-5, -5]
  }),
  e.makeSwitch({
    id: 1,
    pos: [-2, -5]
  }),
  e.makeSwitch({
    id: 2,
    pos: [1, -5]
  }),
  e.makeSwitch({
    id: 3,
    pos: [4, -5]
  }),
  e.makeLaserEmitter({
    id: 4,
    "on": true,
    start: [-15, 3],
    end: [15, 3],
    rotation: -90
  }),
  e.makeLaserDetector({
    id: 5,
    emitter: 4,
    pos: [15, 3],
    rotation: 90
  }),
  e.makeDoor({
    "in": [0, 1],
    operator: "or",
    pos: [-10.5, 1],
    size: [1, 4]
  }),
  e.makeDoor({
    "in": [0, 2],
    operator: "xor",
    pos: [-3.5, 1],
    size: [1, 4]
  }),
  e.makeDoor({
    "in": 2,
    pos: [3.5, 1],
    size: [1, 4]
  }),
  e.makeDoor({
    "in": 3,
    operator: "not",
    pos: [10.5, 1],
    size: [1, 4]
  })
]
