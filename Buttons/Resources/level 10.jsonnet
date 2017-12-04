local e = import "entities.jsonnet";
//e\.platform\.makePosSize\((\[[-.\d]+, [-.\d]+\]), (\[[-.\d]+, [-.\d]+\])\)
[
  e.makePlatform({
    pos: [-16, -9],
    size: [32, 1]
  }),
  e.makePlatform({
    pos: [-16, -8],
    size: [1, 17]
  }),
  e.makePlatform({
    pos: [-7, -8]
  }),
  e.makePlatform({
    pos: [-9, -7],
    size: [3, 1]
  }),
  e.makePlayer({
    pos: [-15, -8]
  }),
  e.makeExit({
    pos: [-8, -8]
  }),
  e.lock.makeIdIndexPos(0, 0, [-11, -8]),
  e.door.makeInPos(0, [-8.5, -8]),
  e.switch.makeIdPos(10, [-13, -8]),
 
  {
    "file": "moving platform entity.json",
    "components": {
      "PhysicsBody": {
        "body": "platform body.json",
        "pos": [-15, -9],
        "scale": [2, 1]
      },
      "PowerInput": {
        "in": 10
      },
      "MovingPlatform": {
        "start": [-15, -9],
        "end": [-15, -1],
        "speed": 0.1,
        "waiting time": 2.0
      }
    }
  },
  e.makePlatform({
    pos: [-13, -1],
    size: [5, 1]
  }),
  e.makePlatform({
    pos: [-9, 0]
  }),
  e.makePlatform({
    pos: [-11, 1],
    size: [3, 1]
  }),
  e.key.makeIndexPos(0, [-10, 0]),
  e.lock.makeIdIndexPos(1, 1, [-13, 0]),
  e.door.makeInPos(1, [-10.5, 0])
]
