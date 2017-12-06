local e = import "entities.jsonnet";

[
  e.makePlatform({
    pos: [0, 0],
    size: [32, 7]
  }),
  e.makePlatform({
    pos: [0, 7],
    size: [9, 4]
  }),
  e.makePlatform({
    pos: [0, 11],
    size: [32, 7]
  }),
  e.makePlatform({
    pos: [23, 7],
    size: [9, 4]
  }),
  e.makePlatform({
    pos: [13, 8],
    size: [10, 1]
  }),
  e.makePlatform({
    pos: [17, 9],
    size: [2, 2]
  }),
  e.makePlayer({
    pos: [9, 7]
  }),
  e.makeExit({
    pos: [22, 7]
  }),
  e.makeBox({
    pos: [19, 9]
  }),
  e.makeSwitch({
    pos: [16, 9]
  }),
  e.makeButton({
    pos: [22, 9]
  }),
  e.makeSwitch({
    id: 0,
    pos: [16, 7]
  }),
  e.makeButton({
    id: 1,
    pos: [19, 9]
  }),
  e.makeDoor({
    "in": [0, 1],
    operator: "and",
    pos: [19, 7]
  }),
  e.makeLaserEmitter({
    id: 2,
    "on": true,
    start: [9, 8.5],
    end: [13, 8.5],
    rotation: -90
  }),
  e.makeLaserDetector({
    id: 3,
    emitter: 2,
    pos: [13, 8.5],
    rotation: 90
  }),
  e.makeMovingPlatform({
    "in": 3,
    operator: "not",
    start: [18, 9],
    end: [19, 9],
    size: [1, 2],
    speed: 10
  }),
  e.makeText({
    pos: [16, 13],
    text: "Press R to reload the level"
  })
]
