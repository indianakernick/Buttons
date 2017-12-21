local common = import "common.jsonnet";

function(params) {
  [if "id" in params then "id"]: params.id,
  components: common.checkParams(params, ["id", "pos", "index"]) {
    Activation: {},
    Collision: {},
    ActiveSpriteRendering: {
      sprite: "lock " + params.index,
      frames: 1
    },
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
