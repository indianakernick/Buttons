local e = import "entities.jsonnet";

[
  e.makePlatform({
    pos: [-16, -9],
    size: [32, 7]
  }),
  e.makePlatform({
    pos: [-16, -2],
    size: [9, 4]
  }),
  e.makePlatform({
    pos: [-16, 2],
    size: [32, 7]
  }),
  e.makePlatform({
    pos: [7, -2],
    size: [9, 4]
  }),
  e.makePlatform({
    pos: [-3, -1],
    size: [10, 1]
  }),
  e.makePlatform({
    pos: [1, 0],
    size: [2, 2]
  }),
  e.makePlayer({
    pos: [-7, -2]
  }),
  e.makeExit({
    pos: [6, -2]
  }),
  e.makeBox({
    pos: [3, 0]
  }),
  e.makeSwitch({
    pos: [0, 0]
  }),
  e.makeButton({
    pos: [6, 0]
  }),
  e.makeSwitch({
    id: 0,
    pos: [0, -2]
  }),
  e.makeButton({
    id: 1,
    pos: [3, 0]
  }),
  e.makeDoor({
    "in": [0, 1],
    operator: "and",
    pos: [3.5, -2]
  }),
  e.makeLaserEmitter({
    id: 2,
    "on": true,
    start: [-7, -0.5],
    end: [-3, -0.5],
    rotation: -90
  }),
  e.makeLaserDetector({
    id: 3,
    emitter: 2,
    pos: [-3, -0.5],
    rotation: 90
  }),
  e.makeMovingPlatform({
    "in": 3,
    operator: "not",
    start: [2, 0],
    end: [3, 0],
    size: [1, 2],
    speed: 10
  }),
  e.makeText({
    pos: [0, 4],
    text: "Press R to reload the level"
  })
]
