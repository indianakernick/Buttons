local common = import "common components.jsonnet";

function(params) {
  [if "id" in params then "id"]: params.id,
  components: {
    Activation: {
      speed: 4
    },
    Collision: {},
    PowerOutput: {},
    Switch: {},
    SwitchRendering: {},
    Transform: {},
    PhysicsBody: common.transformParams(params) + {
      body: "sensor body.json"
    }
  }
}
