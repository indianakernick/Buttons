local common = import "common.jsonnet";

function(params) {
  [if "id" in params then "id"]: params.id,
  components: common.checkParams(params, ["id", "pos", "index"]) {
    Activation: {
      speed: 4
    },
    Animation: {
      speed: 0
    },
    AnimSpriteRendering: {
      sprite: "lock " + params.index + " 0",
      frames: 6,
      depth: common.getDepth("lock")
    },
    Collision: {},
    PowerOutput: {},
    Transform: {},
    PhysicsBody: common.getPos(params) + {
      body: (import "sensor body.json")
    },
    Lock: {
      index: params.index
    }
  }
}
