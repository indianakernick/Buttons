local common = import "common.jsonnet";

function(params) {
  components: common.checkParams(params, ["pos"]) {
    Activation: {},
    Animation: {
      speed: 1.5
    },
    Collision: {},
    Exit: {},
    ExitRendering: {},
    Transform: {},
    PhysicsBody: common.getPos(params) + {
      body: "sensor body.json"
    }
  }
}
