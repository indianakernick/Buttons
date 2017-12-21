local common = import "common.jsonnet";

function(params) {
  components: common.checkParams(params, ["pos"]) {
    Activation: {},
    Animation: {
      speed: 1.5
    },
    AnimSpriteRendering: {
      sprite: "exit 0",
      frames: 6
    },
    Collision: {},
    Exit: {},
    Transform: {},
    PhysicsBody: common.getPos(params) + {
      body: "sensor body.json"
    }
  }
}
