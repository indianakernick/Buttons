local common = import "common.jsonnet";

function(params) {
  components: common.checkParams(params, ["pos", "index"]) {
    Activation: {
      active: true,
      speed: 4
    },
    Animation: {
      speed: 0
    },
    AnimSpriteRendering: {
      sprite: "key " + params.index + " 0",
      frames: 6,
      depth: common.getDepth("key")
    },
    Collision: {},
    Transform: {},
    PhysicsBody: common.getPos(params) + {
      body: (import "sensor body.json")
    },
    Key: {
      index: params.index
    }
  }
}
