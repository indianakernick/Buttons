local e = import "entities.jsonnet";

[
  e.makePlatform({
    pos: [0, 0],
    size: [32, 8]
  }),
  e.makePlatform({
    pos: [0, 10],
    size: [32, 8]
  }),
  e.makePlatform({
    pos: [0, 8],
    size: [1, 2]
  }),
  e.makePlatform({
    pos: [31, 8],
    size: [1, 2]
  }),
  e.makePlayer({
    pos: [1, 8]
  }),
  e.makeExit({
    pos: [30, 8]
  }),
  e.makeText({
    pos: [16, 11],
    text: "Press A and D or left and right to move"
  })
]
