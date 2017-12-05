local common = import "common.jsonnet";

function(params) {
  components: {
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
