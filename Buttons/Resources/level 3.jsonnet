local box = import "box entity.jsonnet";
local button = import "button entity.jsonnet";
local door = import "door entity.jsonnet";

[
  {
    "file": "platform entity.json",
    "components": {
      "PhysicsBody": {
        "body": "platform body.json",
        "pos": [-16, -9],
        "scale": [32, 7]
      }
    }
  },
  {
    "file": "platform entity.json",
    "components": {
      "PhysicsBody": {
        "body": "platform body.json",
        "pos": [-16, 2],
        "scale": [32, 7]
      }
    }
  },
  {
    "file": "platform entity.json",
    "components": {
      "PhysicsBody": {
        "body": "platform body.json",
        "pos": [-16, -2],
        "scale": [1, 4]
      }
    }
  },
  {
    "file": "platform entity.json",
    "components": {
      "PhysicsBody": {
        "body": "platform body.json",
        "pos": [15, -2],
        "scale": [1, 4]
      }
    }
  },
  {
    "file": "player entity.json",
    "components": {
      "PhysicsBody": {
        "body": "player body.json",
        "pos": [-10, -2]
      }
    }
  },
  {
    "file": "exit entity.json",
    "components": {
      "PhysicsBody": {
        "body": "sensor body.json",
        "pos": [14, -2]
      }
    }
  },
  box.make([-13, -2]),
  button.make(0, [-2, -2]),
  {
    "id": 1,
    "file": "switch entity.json",
    "components": {
      "PhysicsBody": {
        "body": "sensor body.json",
        "pos": [1, -2]
      }
    }
  },
  door.makeInPosSizeRot(1, [5.5, 2], [1, 4], 180),
  {
    "file": "door entity.json",
    "components": {
      "PhysicsBody": {
        "body": "door body.json",
        "pos": [8.5, 2],
        "rotation": 180,
        "scale": [1, 4]
      },
      "PowerInput": {
        "in": 0
      }
    }
  }
]
