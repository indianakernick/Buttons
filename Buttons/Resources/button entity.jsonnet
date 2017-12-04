local common = import "common components.jsonnet";

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
    PhysicsBody: common.transformParams(params) + {
      body: "button body.json"
    }
  }
}
