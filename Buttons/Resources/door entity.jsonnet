local common = import "common.jsonnet";

function(params) {
  components: {
    Activation: {
      speed: 4
    },
    Door: {},
    DoorRendering: {},
    Transform: {},
    PhysicsBody: common.getTransform(params) + {
      body: "door body.json"
    },
    PowerInput: common.getPowerInput(params)
  }
}
