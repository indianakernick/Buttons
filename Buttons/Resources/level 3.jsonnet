local box = import "box entity.jsonnet";
local button = import "button entity.jsonnet";
local door = import "door entity.jsonnet";
local exit = import "exit entity.jsonnet";
local player = import "player entity.jsonnet";
local platform = import "platform entity.jsonnet";
local switch = import "switch entity.jsonnet";

[
  platform.makePosSize([-16, -9], [32, 7]),
  platform.makePosSize([-16, 2], [32, 7]),
  platform.makePosSize([-16, -2], [1, 4]),
  platform.makePosSize([15, -2], [1, 4]),
  player.makePos([-10, -2]),
  exit.makePos([14, -2]),
  box.makePos([-13, -2]),
  button.makeIdPos(0, [-2, -2]),
  switch.makeIdPos(1, [1, -2]),
  door.makeInPosSizeRot(1, [5.5, 2], [1, 4], 180),
  door.makeInPosSizeRot(0, [8.5, 2], [1, 4], 180)
]
