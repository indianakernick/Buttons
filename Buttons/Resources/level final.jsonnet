local e = import "entities.jsonnet";
local headSize = 128;
local bodySize = 64;

[
  e.makeText({
    size: headSize,
    pos: [0, 5],
    text: "Congratulations"
  }),
  e.makeText({
    size: bodySize,
    pos: [0, 2],
    text: "You have just completed Buttons"
  }),
  e.makeText({
    size: bodySize,
    pos: [0, 0.5],
    text: "Now you can accomplish anything"
  }),
  e.makeText({
    size: bodySize,
    pos: [0, -2],
    text: "A game by:"
  }),
  e.makeText({
    size: bodySize,
    pos: [0, -3.5],
    text: "Indi Kernick"
  })
]
