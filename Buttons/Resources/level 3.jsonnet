local box = import "box entity.jsonnet";

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
  {
    "id": 0,
    "file": "button entity.json",
    "components": {
      "PhysicsBody": {
        "body": "button body.json",
        "pos": [-2, -2]
      }
    }
  },
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
  {
    "file": "door entity.json",
    "components": {
      "PhysicsBody": {
        "body": "door body.json",
        "pos": [5.5, 2],
        "rotation": 180,
        "scale": [1, 4]
      },
      "PowerInput": {
        "in": 1
      }
    }
  },
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
