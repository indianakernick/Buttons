local e = import "entities.jsonnet";
local headSize = 6;
local bodySize = 3;

[
  e.makeText({
    "font scale": headSize,
    pos: [16, 13],
    text: "Congratulations"
  }),
  e.makeText({
    "font scale": bodySize,
    pos: [16, 10],
    text: "You have just completed Buttons"
  }),
  e.makeText({
    "font scale": bodySize,
    pos: [16, 8.5],
    text: "Now you can accomplish anything"
  }),
  e.makeText({
    "font scale": bodySize,
    pos: [16, 6],
    text: "A game by"
  }),
  e.makeText({
    "font scale": bodySize,
    pos: [16, 4.5],
    text: "Indi Kernick"
  })
]
