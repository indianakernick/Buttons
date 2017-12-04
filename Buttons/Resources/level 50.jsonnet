local e = import "entities.jsonnet";
local headSize = 128;
local bodySize = 64;

[
  e.text.makePosPointsText([0, 5], headSize, "Congratulations"),
  e.text.makePosPointsText([0, 2], bodySize, "You have just completed Buttons"),
  e.text.makePosPointsText([0, 0.5], bodySize, "Now you can accomplish anything"),
  e.text.makePosPointsText([0, -2], bodySize, "A game by:"),
  e.text.makePosPointsText([0, -3.5], bodySize, "Indi Kernick")
]
