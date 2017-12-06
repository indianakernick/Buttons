local e = import "entities.jsonnet";
local headSize = 128;
local bodySize = 64;

[
  e.makeText({
    "font size": headSize,
    pos: [16, 14],
    text: "Congratulations"
  }),
  e.makeText({
    "font size": bodySize,
    pos: [16, 11],
    text: "You have just completed Buttons"
  }),
  e.makeText({
    "font size": bodySize,
    pos: [16, 9.5],
    text: "Now you can accomplish anything"
  }),
  e.makeText({
    "font size": bodySize,
    pos: [16, 7],
    text: "A game by:"
  }),
  e.makeText({
    "font size": bodySize,
    pos: [16, 5.5],
    text: "Indi Kernick"
  })
]
