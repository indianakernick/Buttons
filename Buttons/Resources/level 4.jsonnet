local e = import "entities.jsonnet";

[
  e.platform.makePosSize([-16, -9], [32, 4]),
  e.platform.makePosSize([-15, -1], [30, 2]),
  e.platform.makePosSize([-16, 5], [32, 4]),
  e.platform.makePosSize([-16, -5], [1, 10]),
  e.platform.makePosSize([15, -5], [1, 10]),
  e.player.makePos([-15, -5]),
  e.exit.makePos([14, -5]),
  e.door.makeInPosSize(5, [9.5, -5], [1, 4]),
  e.laser_emitter.makeIdStartEndRot(4, [-15, 3], [15, 3], -90),
  e.laser_detector.makeIdEmitterPosRot(5, 4, [15, 3], 90),
  e.switch.makeIdPos(0, [-5, -5]),
  e.switch.makeIdPos(1, [-2, -5]),
  e.switch.makeIdPos(2, [1, -5]),
  e.switch.makeIdPos(3, [4, -5]),
  {
    "file": "door entity.json",
    "components": {
      "MultiPowerInput": {
        "in": [0, 1],
        "operator": "or"
      },
      "PhysicsBody": {
        "body": "door body.json",
        "pos": [-10.5, 1],
        "scale": [1, 4]
      }
    }
  },
  {
    "file": "door entity.json",
    "components": {
      "MultiPowerInput": {
        "in": [0, 2],
        "operator": "xor"
      },
      "PhysicsBody": {
        "body": "door body.json",
        "pos": [-3.5, 1],
        "scale": [1, 4]
      }
    }
  },
  {
    "file": "door entity.json",
    "components": {
      "PhysicsBody": {
        "body": "door body.json",
        "pos": [3.5, 1],
        "scale": [1, 4]
      },
      "PowerInput": {
        "in": 2
      }
    }
  },
  {
    "file": "door entity.json",
    "components": {
      "PhysicsBody": {
        "body": "door body.json",
        "pos": [10.5, 1],
        "scale": [1, 4]
      },
      "PowerInput": {
        "in": 3,
        "invert": true
      }
    }
  }
]
