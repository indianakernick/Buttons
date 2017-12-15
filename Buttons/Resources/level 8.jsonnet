local e = import "entities.jsonnet";

[
  // Outside
  e.makePlatform({
    pos: [0, 0],
    size: [32, 2]
  }),
  e.makePlatform({
    pos: [0, 16],
    size: [32, 2]
  }),
  e.makePlatform({
    pos: [0, 2],
    size: [5, 14]
  }),
  e.makePlatform({
    pos: [27, 2],
    size: [5, 14]
  }),

  // Left Platforms
  e.makePlatform({
    pos: [5, 5],
    size: [11, 1]
  }),
  e.makePlatform({
    pos: [5, 9],
    size: [11, 1]
  }),
  e.makePlatform({
    pos: [5, 13],
    size: [11, 1]
  }),

  // Right Platforms
  e.makePlatform({
    pos: [17, 3],
    size: [10, 1]
  }),
  e.makePlatform({
    pos: [17, 7],
    size: [10, 1]
  }),
  e.makePlatform({
    pos: [17, 11],
    size: [10, 1]
  }),

  // Left keys
  e.makeKey({
    index: 4,
    pos: [5, 6]
  }),
  e.makeKey({
    index: 3,
    pos: [5, 10]
  }),
  e.makeKey({
    index: 1,
    pos: [5, 14]
  }),

  // Right keys
  e.makeKey({
    index: 0,
    pos: [26, 4]
  }),
  e.makeKey({
    index: 2,
    pos: [26, 8]
  }),
  e.makeKey({
    index: 5,
    pos: [26, 12]
  }),

  // Locks
  e.makeLock({
    id: 0,
    index: 0,
    pos: [18, 2]
  }),
  e.makeLock({
    id: 1,
    index: 1,
    pos: [20, 2]
  }),
  e.makeLock({
    id: 2,
    index: 2,
    pos: [22, 2]
  }),
  e.makeLock({
    id: 3,
    index: 3,
    pos: [24, 2]
  }),

  // Doors
  e.makeDoor({
    pos: [19, 2],
    "in": 0
  }),
  e.makeDoor({
    pos: [21, 2],
    "in": 1
  }),
  e.makeDoor({
    pos: [23, 2],
    "in": 2
  }),
  e.makeDoor({
    pos: [25, 2],
    "in": 3
  }),

  // Player and Exit
  e.makePlayer({
    pos: [5, 2]
  }),
  e.makeExit({
    pos: [26, 2]
  })
]
