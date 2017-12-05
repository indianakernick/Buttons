local common = import "common.jsonnet";

function(params) {
  [if "id" in params then "id"]: params.id,
  components: {
    Activation: {
      speed: 8
    },
    Button: {},
    ButtonRendering: {},
    Collision: {},
    PowerOutput: {},
    Transform: {},
    PhysicsBody: common.getTransform(params) + {
      body: "button body.json"
    }
  }
}
