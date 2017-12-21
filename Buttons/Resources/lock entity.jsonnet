local common = import "common.jsonnet";

function(params) {
  [if "id" in params then "id"]: params.id,
  components: common.checkParams(params, ["id", "pos", "index"]) {
    Activation: {},
    Animation: {
      speed: 0
    },
    AnimSpriteRendering: {
      sprite: "lock " + params.index,
      frames: 1
    },
    Collision: {},
    PowerOutput: {},
    Transform: {},
    PhysicsBody: common.getPos(params) + {
      body: "sensor body.json"
    },
    Lock: {
      index: params.index
    }
  }
}
