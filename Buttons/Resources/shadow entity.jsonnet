local common = import "common components.jsonnet";

function(params) {
  components: {
    Activation: {
      speed: 0.5
    },
    ShadowRendering: {},
    Transform: common.transformParams(params)
  }
}
