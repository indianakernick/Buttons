[
  {
    "file": "platform entity.json",
    "components": {
      "PhysicsBody": {
        "pos": [-16, -9],
        "scale": [32, 1],
        "body": "platform body.json"
      }
    }
  },
  {
    "file": "platform entity.json",
    "components": {
      "PhysicsBody": {
        "pos": [-16, -8],
        "scale": [1, 17],
        "body": "platform body.json"
      }
    }
  },
  {
    "file": "platform entity.json",
    "components": {
      "PhysicsBody": {
        "pos": [-7, -8],
        "scale": [1, 1],
        "body": "platform body.json"
      }
    }
  },
  {
    "file": "platform entity.json",
    "components": {
      "PhysicsBody": {
        "pos": [-9, -7],
        "scale": [3, 1],
        "body": "platform body.json"
      }
    }
  },
  {
    "file": "player entity.json",
    "components": {
      "PhysicsBody": {
        "pos": [-15, -8],
        "body": "player body.json"
      }
    }
  },
  {
    "file": "exit entity.json",
    "components": {
      "PhysicsBody": {
        "pos": [-8, -8],
        "body": "sensor body.json"
      }
    }
  },
  {
    "id": 0,
    "file": "lock entity.json",
    "components": {
      "PhysicsBody": {
        "pos": [-11, -8],
        "body": "sensor body.json"
      },
      "Lock": {
        "index": 0
      }
    }
  },
  {
    "file": "door entity.json",
    "components": {
      "PhysicsBody": {
        "pos": [-8.5, -8],
        "body": "door body.json"
      },
      "PowerInput": {
        "in": 0
      }
    }
  },
  {
    "id": 10,
    "file": "switch entity.json",
    "components": {
      "PhysicsBody": {
        "pos": [-13, -8],
        "body": "sensor body.json"
      }
    }
  },
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
  {
    "file": "platform entity.json",
    "components": {
      "PhysicsBody": {
        "pos": [-13, -1],
        "scale": [5, 1],
        "body": "platform body.json"
      }
    }
  },
  {
    "file": "platform entity.json",
    "components": {
      "PhysicsBody": {
        "pos": [-9, 0],
        "scale": [1, 1],
        "body": "platform body.json"
      }
    }
  },
  {
    "file": "platform entity.json",
    "components": {
      "PhysicsBody": {
        "pos": [-11, 1],
        "scale": [3, 1],
        "body": "platform body.json"
      }
    }
  },
  {
    "file": "key entity.json",
    "components": {
      "PhysicsBody": {
        "pos": [-10, 0],
        "body": "sensor body.json"
      },
      "Key": {
        "index": 0
      }
    }
  },
  {
    "id": 1,
    "file": "lock entity.json",
    "components": {
      "PhysicsBody": {
        "pos": [-13, 0],
        "body": "sensor body.json"
      },
      "Lock": {
        "index": 1
      }
    }
  },
  {
    "file": "door entity.json",
    "components": {
      "PhysicsBody": {
        "pos": [-10.5, 0],
        "body": "door body.json"
      },
      "PowerInput": {
        "in": 1
      }
    }
  }
]
