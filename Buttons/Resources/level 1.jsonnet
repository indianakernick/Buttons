local e = import "entities.jsonnet";

[
  e.makePlatform({
    pos: [0, 0],
    size: [32, 1]
  }),
  e.makePlatform({
    pos: [0, 17],
    size: [32, 1]
  }),
  e.makePlatform({
    pos: [0, 1],
    size: [1, 16]
  }),
  e.makePlatform({
    pos: [31, 1],
    size: [1, 16]
  }),
  e.makePlatform({
    pos: [3, 1]
  }),
  e.makePlatform({
    pos: [8, 1],
    size: [1, 2]
  }),
  e.makePlatform({
    pos: [11, 4],
    size: [4, 1]
  }),
  e.makePlatform({
    pos: [19, 1],
    size: [1, 4]
  }),
  e.makePlatform({
    pos: [26, 2],
    size: [5, 1]
  }),
  e.makePlayer({
    pos: [1, 1]
  }),
  e.makeExit({
    pos: [30, 3]
  }),
  e.makeText({
    pos: [16, 9],
    text: "Press W or up to jump"
  })
]
