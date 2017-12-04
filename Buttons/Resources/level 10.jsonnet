local e = import "entities.jsonnet";

[
  e.makePlatform({
    pos: [-16, -9],
    size: [32, 1]
  }),
  e.makePlatform({
    pos: [-16, -8],
    size: [1, 17]
  }),
  e.makePlatform({
    pos: [-7, -8]
  }),
  e.makePlatform({
    pos: [-9, -7],
    size: [3, 1]
  }),
  e.makePlayer({
    pos: [-15, -8]
  }),
  e.makeExit({
    pos: [-8, -8]
  }),
  e.makeLock({
    id: 0,
    index: 0,
    pos: [-11, -8]
  }),
  e.makeDoor({
    "in": 0,
    pos: [-8.5, -8]
  }),
  e.makeSwitch({
    id: 10,
    pos: [-13, -8]
  }),
  e.makeMovingPlatform({
    "in": 10,
    start: [-15, -9],
    end: [-15, -1],
    size: [2, 1],
    speed: 0.1,
    "waiting time": 2.0
  }),
  e.makePlatform({
    pos: [-13, -1],
    size: [5, 1]
  }),
  e.makePlatform({
    pos: [-9, 0]
  }),
  e.makePlatform({
    pos: [-11, 1],
    size: [3, 1]
  }),
  e.makeKey({
    index: 0,
    pos: [-10, 0]
  }),
  e.makeLock({
    id: 1,
    index: 1,
    pos: [-13, 0]
  }),
  e.makeDoor({
    "in": 1,
    pos: [-10.5, 0]
  })
]
