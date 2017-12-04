local e = import "entities.jsonnet";

[
  e.makePlatform({
    pos: [-16, -9],
    size: [32, 1]
  }),
  e.makePlatform({
    pos: [-16, 8],
    size: [32, 1]
  }),
  e.makePlatform({
    pos: [-16, -8],
    size: [1, 16]
  }),
  e.makePlatform({
    pos: [15, -8],
    size: [1, 16]
  }),
  e.makePlatform({
    pos: [-13, -8]
  }),
  e.makePlatform({
    pos: [-8, -8],
    size: [1, 2]
  }),
  e.makePlatform({
    pos: [-5, -5],
    size: [4, 1]
  }),
  e.makePlatform({
    pos: [3, -8],
    size: [1, 4]
  }),
  e.makePlatform({
    pos: [10, -7],
    size: [5, 1]
  }),
  e.makePlayer({
    pos: [-15, -8]
  }),
  e.makeExit({
    pos: [14, -6]
  }),
  e.text.makePosText([0, 0], "Press W or up to jump")
]
