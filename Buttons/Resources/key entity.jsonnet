local common = import "common.jsonnet";

function(params) {
  components: common.checkParams(params, ["pos", "index"]) {
    Activation: {
      active: true,
      speed: 4
    },
    Collision: {},
    ActiveSpriteRendering: {
      sprite: "key " + params.index + " 0",
      frames: 5
    },
    Transform: {},
    PhysicsBody: common.getPos(params) + {
      body: "sensor body.json"
    },
    Key: {
      index: params.index
    }
  }
}
