local e = import "entities.jsonnet";
local headSize = 8;
local bodySize = 4;

[
  e.makeText({
    "font scale": headSize,
    pos: [16, 14],
    text: "Congratulations"
  }),
  e.makeText({
    "font scale": bodySize,
    pos: [16, 11],
    text: "You have just completed Buttons"
  }),
  e.makeText({
    "font scale": bodySize,
    pos: [16, 9.5],
    text: "Now you can accomplish anything"
  }),
  e.makeText({
    "font scale": bodySize,
    pos: [16, 7],
    text: "A game by"
  }),
  e.makeText({
    "font scale": bodySize,
    pos: [16, 5.5],
    text: "Indi Kernick"
  })
]
