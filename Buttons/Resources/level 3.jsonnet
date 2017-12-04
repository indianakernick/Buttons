local e = import "entities.jsonnet";

[
  e.platform.makePosSize([-16, -9], [32, 7]),
  e.platform.makePosSize([-16, 2], [32, 7]),
  e.platform.makePosSize([-16, -2], [1, 4]),
  e.platform.makePosSize([15, -2], [1, 4]),
  e.player.makePos([-10, -2]),
  e.exit.makePos([14, -2]),
  e.box.makePos([-13, -2]),
  e.button.makeIdPos(0, [-2, -2]),
  e.switch.makeIdPos(1, [1, -2]),
  e.door.makeInPosSizeRot(1, [5.5, 2], [1, 4], 180),
  e.door.makeInPosSizeRot(0, [8.5, 2], [1, 4], 180)
]
